from django.shortcuts import render
from .forms import CarForm

# Create your views here.

def home(request):
    context = {}
    form = CarForm(request.POST or None)
    context['form'] = form
    return render(request,'Q1/home.html',context)

def display(request):
    context = {}
    manufacturer = 'Chevy'
    model = 'Impala 1967'
    if request.method == "POST":
        loginform  = CarForm(request.POST)
        if loginform.is_valid():
            manufacturer = loginform.cleaned_data['manufacturer']
            model = loginform.cleaned_data['model']
        else:
            loginform  = CarForm()
    context['manufacturer'] = manufacturer
    context['model'] = model
    return render(request,'Q1/display.html',context)
