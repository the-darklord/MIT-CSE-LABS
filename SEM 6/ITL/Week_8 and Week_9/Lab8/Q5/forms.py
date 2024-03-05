from django import forms

class SurveyForm(forms.Form):
     choices = (
          ('Good','Good'),
          ('Satisfactory','Satisfactory'),
          ('Bad','Bad'),
     )
     res = forms.ChoiceField(widget=forms.RadioSelect(choices=choices))

