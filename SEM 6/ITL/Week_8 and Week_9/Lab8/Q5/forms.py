from django import forms
 
class SelectForm(forms.Form):
	CHOICES = (('good','Good'),('satisfactory','Satisfactory'),('bad','Bad'))
	res = forms.ChoiceField(widget=forms.RadioSelect(),choices=CHOICES)