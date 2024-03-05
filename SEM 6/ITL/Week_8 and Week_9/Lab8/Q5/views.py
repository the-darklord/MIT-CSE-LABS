from django.shortcuts import render
from .forms import SurveyForm

# Create your views here.

def survey(request):
    pgood = 1
    psat = 1
    pbad = 1
    if request.method=="GET":
        return render(request,'Q5/survey.html')
    elif request.method=="POST":
        form = SurveyForm(request.POST)
        if form.is_valid():
            res = request.POST['res']
            if res=='Good':
                pgood += 1
            elif res=='Satisfactory':
                psat += 1
            else:
                pbad += 1
    else:
        form = SurveyForm()
    
    pgood = pgood*100/4
    psat = psat*100/4
    pbad = pbad*100/4
            
    return render(request,'Q5/survey.html',{'pgood':pgood,'psat':psat,'pbad':pbad})