from django import forms

class CarForm(forms.Form):
    mans=(
        ('Chevy','Chevy'),
        ('Ferari','Ferari'),
        ('Lambo','Lambo'),
        )
    manufacturer = forms.ChoiceField(widget=forms.Select,choices=mans)
    model = forms.CharField()