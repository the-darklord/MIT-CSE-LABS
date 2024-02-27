from django import forms

class RegForm(forms.Form):
    title = forms.CharField()
    description = forms.CharField()
    views = forms.IntegerField()
    available = forms.BooleanField()

class GeeksForm(forms.Form): 
    title = forms.CharField(widget = forms.Textarea) 
    description = forms.CharField(widget = forms.Textarea) 
    views = forms.IntegerField(widget = forms.TextInput) 
    available = forms.BooleanField(widget = forms.CheckboxInput)
    
#class LoginForm(forms.Form): 
 #   username = forms.CharField(max_length = 100) 
 #  contact_num = forms.IntegerField()
    
class LoginForm(forms.Form): 
    username = forms.CharField(max_length = 100)
    password = forms.CharField(widget= forms.PasswordInput()) 