import pstats
from django.shortcuts import render,HttpResponse
from .forms import SelectForm
 
def survey(request):
	if request.method == "GET":
		return render(request,'Q5/survey.html')
	elif request.method == "POST":
		pgood = 1
		psatis = 1
		pbad = 1
 
		formres = SelectForm(request.POST)
		if formres.is_valid():
			res = formres.cleaned_data['res']
			if(res == "good"):
				pgood += 1
			elif(res == "satisfactory"):
				psatis += 1
			else:
				pbad += 1
		else:
			return HttpResponse("Invalid Form")
 
		pgood = (pgood/4)* 100
		psatis = (psatis/4)* 100
		pbad = (pbad/4)* 100
		context = {"pgood":pgood,"psatis":psatis,"pbad":pbad}
		return render(request,'Q5/survey.html',context)