from django.contrib import admin
from django.contrib.auth.models import User

from mos.cal.models import Event, Category, Location
from mos.members.models import MemberAdmin
from mos.projects.models import Project

#models for event admin site
calendar_admin = admin.AdminSite()
calendar_admin.register(Event)
calendar_admin.register(Category)
calendar_admin.register(Location)

#models for project admin site
project_admin = admin.AdminSite()
project_admin.register(Project)

#models for user admin site
member_admin = admin.AdminSite()
member_admin.register(User, MemberAdmin)
