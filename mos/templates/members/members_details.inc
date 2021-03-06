<table id="table_user_details" width="800">
{% ifequal error_type "permission" %}
   <tr>
     <td colspan="3">
     </td>
   </tr>
{% endifequal %}
	<tr>
		<td rowspan="40" width="100px" style="text-align:center">
			{% if item.contactinfo_set.all.0.image %}
				<img class="thumb_with_text" src="{{ item.contactinfo_set.all.0.image.url }}"/>
			{% else %}
				<img src="/site_media/images/default_avatar.png"/>
			{% endif %}
		</td>
		<td width="150px"><b>Info</b></td>
		<td></td>
	</tr>
	<tr>
		<td>Name:</td>
        <td>{{ item.first_name }} {{ item.last_name }} </td><td>{% if ea%}<a align="right" href='#'  onclick="set_visible($('member-edit-name')); return false;">Edit</a>{% endif %}</td>
    </tr>
    <tr>
         <td colspan="3">  
            {% if ea %}
            <div class="edit {% ifequal error_type "name" %} visible {% else %} invisible {% endifequal %}" id='member-edit-name' style="border: 1px solid black; padding: 5px;">
                <form id='membmer-form-name' method="post" action="/member/{{user.username}}/update/name/" onsubmit="return false;" onKeyPress="
                if(enter_pressed(event)) {
                    myform = $('member-form-name');
                    new Ajax.Updater( $('container'), myform.readAttribute('action'), {
                      parameters: myform.serialize(true),
                    });
                }
                ">
                    <dt><label>First Name</label> - <label>Last Name</label></dt>
		  {%  ifequal error_type "name" %}
		    <dd>{{ error_form.first_name.errors.0 }}  {{ error_form.first_name }} - {{ error_form.last_name.errors.0 }}  {{ error_form.last_name }}</dd>
		  {% else %}
		    <dd>
                        <input name='first_name' id="member-first_name" type="text" value='{{item.first_name}}'/>  - 
                        <input name='last_name' id="member-last_name" type="text" value='{{item.last_name}}'/>
                    </dd>
                  {% endifequal %}                    
                    <dt style="visibility: hidden">Submit:</dt>
                    <dd style="text-align: left">
                        <input type="button" value="Update" class="btn-update" onclick="
                        new Ajax.Updater( $('container'), $('membmer-form-name').readAttribute('action'), {
                          parameters: $('membmer-form-name').serialize(true),
                        });
                        "/>	
                    
                        <a href="#" class="toggled btn-cancel" onclick="set_invisible($('member-edit-name')); return false;">Cancel</a></dd>

                </form>
            </div>
            {% endif %}
        </td>
	</tr>
    

	<tr>
		<td>Member since:</td>
	        <td>{{ item.contactinfo_set.all.0.get_date_of_entry|date }}</td>

    	</tr>
{% if ea %}
   <tr><td colspan="3"><hr/></td></tr>
    <tr>
        <td colspan="3"><a href="/member/change_password/" title="Change Password">Change Password</a></th>
    </tr>
    <tr>
        <td colspan="3"><a href="/member/{{user.username}}/update/userpic/" title="Change Userpic">Change Userpic</a></th>
    </tr>
   <tr><td colspan="3"><hr/></td></tr>
{% endif %}
    
	<tr>
		<td><br></td>
		<td></td>
	</tr>
	<tr>
		<td><b>Contact info</b></td>
		<td></td>
	</tr>
	<tr id='member-tr-email'>
		<td>Email:</td>
		<td>{{ item.email }}</td><td> {% if ea%}<a href='#'  onclick="set_visible($('member-edit-email')); return	false;">Edit</a>{% endif %}</td>
	</tr>
    <tr>    
         <td colspan="3">  
            {% if ea %}
            <div class="edit {% ifequal error_type "email" %} visible {% else %} invisible {% endifequal %}" id='member-edit-email' style="border: 1px solid black; padding: 5px; width:100%;">
                <form id='membmer-form-email' method="post" action="/member/{{user.username}}/update/email/" onsubmit="return false;" onKeyPress="
                if(enter_pressed(event)) {
                    myform = $('member-form-email');
                    new Ajax.Updater( $('container'), myform.readAttribute('action'), {
                      parameters: myform.serialize(true),
                    });
                }
                ">
		  {% ifequal error_type "email" %}
		    <dt>New Email</dt>
		    <dd>{{ error_form.email.errors.0 }}   {{ error_form.email }} </dd>
		  {% else %}
                    <dt>New Email </dt>
                    <dd><input name='email' id="member-email" type="text" value='{{item.email}}' size="40"/></dd>
                  {% endifequal %}
            
                    <dt style="visibility: hidden">Submit:</dt>
                    <dd style="text-align: left">
                        <input type="button" value="Update" class="btn-update" onclick="
                        new Ajax.Updater( $('container'), $('membmer-form-email').readAttribute('action'), {
                          parameters: $('membmer-form-email').serialize(true),
                        });
                        "/>	
                    
                        <a href="#" class="toggled btn-cancel" onclick="set_invisible($('member-edit-email')); return false;">Cancel</a>

                </form>
            </div>
            {% endif %}
        </td>
    </tr>
	<tr>
		<td>Adress:</td>
		<td>{{ item.contactinfo_set.all.0.street }}; {{ item.contactinfo_set.all.0.postcode }} {{ item.contactinfo_set.all.0.city }}; {{ item.contactinfo_set.all.0.country }}</td><td> {% if ea%}<a href='#'  onclick="set_visible($('member-edit-adress')); return	false;">Edit</a>{% endif %}</td>
	</tr>
    
    <tr>
        <td colspan="3">
            {% if ea %}
            <div class="edit  {% ifequal error_type "adress" %} visible {% else %} invisible {% endifequal %}"  id='member-edit-adress' style="border: 1px solid black; padding: 5px; width:100%;">
                <form id='membmer-form-adress' method="post" action="/member/{{user.username}}/update/adress/" onsubmit="return false;" onKeyPress="
                if(enter_pressed(event)) {
                    myform = $('member-form-adress');
                    new Ajax.Updater( $('container'), myform.readAttribute('action'), {
                      parameters: myform.serialize(true),
                    });
                }
                ">
                    <dt><label>Street</label> - <label>Postcode</label></dt>
		  {% ifequal error_type "adress" %}
		    <dd>{{ error_form.street.errors.0 }}  {{ error_form.street }} - {{ error_form.postcode.errors.0 }}  {{ error_form.postcode }}</dd>

                    <dt><label>City</label> - <label>Country</label></dt>

		    <dd>{{ error_form.city.errors.0 }}  {{ error_form.city }} - {{ error_form.country.errors.0 }}  {{ error_form.country }} </dd>

		  {% else %}

                    <dd>
                        <input name='street' id="member-street" type="text" value='{{ item.contactinfo_set.all.0.street }}'/>  - 
                        <input name='postcode' id="member-postcode" size="6" type="text" value=' {{ item.contactinfo_set.all.0.postcode }}'/>
                    </dd>
                    <dt><label>City</label> - <label>Country</label></dt>
                        <input name='city' id="member-city" type="text" value=' {{ item.contactinfo_set.all.0.city }}'/> - 
                        <input name='country' id="member-country" type="text" value=' {{ item.contactinfo_set.all.0.country }}'/>
                    </dd>
		  {% endifequal %}

                    <dt style="visibility: hidden">Submit:</dt>
                    <dd style="text-align: left">
                        <input type="button" value="Update" class="btn-update" onclick="
                        new Ajax.Updater( $('container'), $('membmer-form-adress').readAttribute('action'), {
                          parameters: $('membmer-form-adress').serialize(true),
                        });
                        "/>	
                    
                        <a href="#" class="toggled btn-cancel" onclick="set_invisible($('member-edit-adress')); return false;">Cancel</a>
                </form>
            </div>
            {% endif %}
        </td>
    </tr>
    
	<tr>
		<td>On intern list</td>
		{% if item.contactinfo_set.all.0.on_intern_list %}
			<td>yes ( {{ item.contactinfo_set.all.0.intern_list_email }} )</td>
		{% else %}
			<td>no</td>
		{% endif %}
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td>Wiki name:</td>
		<td>{{ item.contactinfo_set.all.0.wiki_name }}</td>
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td>Phone number:</td>
		<td>{{ item.contactinfo_set.all.0.phone_number }}</td>
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td>Birthday:</td>
		<td>{{ item.contactinfo_set.all.0.birthday }}</td>
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td><br></td>
		<td></td>
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td><b>Bank data</b></td>
		<td></td>
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td>Bank collection allowed:</td>
		{% if item.paymentinfo_set.all.0.bank_collection_allowed %}
			<td>yes</td>
		{% else %}
			<td>no</td>
		{% endif %}
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td>Bank account owner:</td>
		<td>{{ item.paymentinfo_set.all.0.bank_account_owner }}</td>
	</tr>
	
    <tr><td></td></tr>
    
    <tr>
		<td>Bank account number:</td>
		<td>{{ item.paymentinfo_set.all.0.bank_account_number }}</td>
	</tr>
    
    <tr><td></td></tr>
    
	<tr>
		<td>Bank name:</td>
		<td>{{ item.paymentinfo_set.all.0.bank_name }}</td>
	</tr>
    
    <tr><td></td></tr>

	<tr>
		<td>Bank code:</td>
		<td>{{ item.paymentinfo_set.all.0.bank_code }}</td>
	</tr>

    <tr><td></td></tr>

	<tr>
		<td>Mode:</td>
		<td>{{ item.paymentinfo_set.all.0.bank_collection_mode }}</td>
	</tr>

    <tr><td></td></tr>

	<tr>
		<td><br></td>
		<td></td>
	</tr>

    <tr><td></td></tr>

	<tr>
		<td><b>Payments</b></td>
		<td></td>
	</tr>
	{% for p in item.payment_set.all %}
		<tr>
			<td>{{ p.amount }} Euro</td>
			<td>payed on {{ p.date|date:"d.m.Y" }} ({{ p.comment }} {{ p.method }})</td>
		</tr>
	{% endfor %}
	<tr>
		<td><br></td>
		<td></td>
	</tr>
	<tr>
		<td><b>Membership periods</b></td>
		<td></td>
	</tr>
	{% for mp in item.membershipperiod_set.all %}
		<tr>
			<td>{{ mp.begin|date:"d.m.Y" }} - {% if mp.end %}{{ mp.end|date:"d.m.Y" }}{% else %}now{% endif %}</td>
			<td>{{ mp.get_duration_in_month }} month as {{ mp.kind_of_membership }}</td>
		</tr>
	{% endfor %}
</table>
