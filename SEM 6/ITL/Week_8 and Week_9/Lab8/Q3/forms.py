from django import forms

class LoginForm(forms.Form):
     username = forms.CharField(required=True)
     password = forms.CharField(widget=forms.PasswordInput(),required=False)
     emailid = forms.CharField(widget=forms.EmailInput(),required=False)
     number = forms.CharField(widget=forms.NumberInput(),required=False)
