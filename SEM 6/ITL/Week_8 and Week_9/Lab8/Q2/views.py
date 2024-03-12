from django.shortcuts import render
from .forms import SubjectForm
 
def firstPage(request):
	return render(request,'Q2/firstPage.html')
 
def secondPage(request):
	name = 'none'
	roll = 0
	subject = 'none'
 
	if request.method == 'POST':
		formres = SubjectForm(request.POST)
		if formres.is_valid():
			name = formres.cleaned_data['name']
			roll = formres.cleaned_data['roll']
			subject = formres.cleaned_data['subjects']
			request.session['name'] = name
			request.session['roll'] = roll
			request.session['subject'] = subject
		else:
			formres = SubjectForm()
	else:
		if request.session.has_key("name"):
			name = request.session['name']
			roll = request.session['roll']
			subject = request.session['subject']
		else:
			return render(request,'firstPage.html',{ })
	context = {"name" : name, "roll":roll,"subject":subject}
	return render(request,'Q2/secondPage.html',context)