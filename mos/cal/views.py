# Create your views here.
from dateutil.parser import *
from django.contrib.auth.decorators import login_required
from django.shortcuts import render_to_response, get_object_or_404
from django.template import RequestContext
from django.core.exceptions import ObjectDoesNotExist

from mos.cal.forms import EventForm
from mos.cal.models import Event, Category, Location


def display_special_events(request, typ, name):
    try:
        if typ == 'Category':
            events = Event.objects.filter(category__name=name)
            des = get_object_or_404(Category, name=name)
        elif typ == 'Location' :
            events = Event.objects.filter(location__name=name)
            des = get_object_or_404(Location, name=name) 
        else : 
            events = None
            des = None
    
    except ObjectDoesNotExist :
        events = None

    return render_to_response('cal/event_archive.html',
                              {'latestevents' : events,
                               'title' : name,
                               'type' : typ,
                               'description' : des},
                              context_instance=RequestContext(request)
                              )
    
@login_required
def delete_event(request, object_id=None):
    if not request.method == 'POST' or not request.user.is_authenticated():
        return
    
    event = Event.all.get(id=object_id)
    
    #event.delete()
    event.deleted = True
    event.save()
    
    latest = Event.future.all()
    return render_to_response('cal/calendar.inc', {
        'latestevents': latest,
        }, context_instance=RequestContext(request)
    )
    
    
@login_required
def update_event(request, new, object_id=None):
    if not request.POST or not request.user.is_authenticated():
        return

    if not new:
        event = Event.all.get(id=object_id)
    else:
        event = Event()

    event_error_id = ' '

    if request.method == 'POST':
        event_form = EventForm(request.POST,instance=event)
   
        if event_form.is_valid():
            event_data = event_form.save(commit=False)
            event_data.save(request.user,new)
            event = Event.objects.get(id=event_data.id)
        else:
            event_error_id = event.id
        
    else:
        event_form = EventForm()

    return render_to_response('cal/eventinfo_nf.inc', {
        'event_error_id': event_error_id, 
        'event_form' : event_form,
        'event' : event,
        'new': not event.pk,
        }, context_instance=RequestContext(request)
    )

