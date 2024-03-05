from django.shortcuts import render
from .forms import MarksForm

# Create your views here.

def calculate(request):
    context = {}
    form = MarksForm(request.POST or None)
    context['form'] = form
    return render(request,'Q4/home.html',context)

def result(request):
    name = None
    marks = None
    if request.method=="POST":
        form = MarksForm(request.POST)
        if form.is_valid():
            name = request.POST['name']
            marks = request.POST['marks']
    else:
        form = MarksForm()
    cgpa = int(marks)/50
            
    return render(request,'Q4/result.html',{'name':name,'cgpa':cgpa})