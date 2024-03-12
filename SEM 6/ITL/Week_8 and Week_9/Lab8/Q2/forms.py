from django import forms
 
class SubjectForm(forms.Form):
	name = forms.CharField()
	roll = forms.IntegerField()
	CHOICES = (('Math','Math'),('Science','Science'))
	subjects = forms.ChoiceField(widget=forms.Select,choices=CHOICES)
