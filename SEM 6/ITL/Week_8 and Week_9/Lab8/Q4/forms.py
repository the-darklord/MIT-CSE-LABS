from django import forms

class MarksForm(forms.Form):
     name = forms.CharField()
     marks = forms.CharField(widget=forms.NumberInput())

