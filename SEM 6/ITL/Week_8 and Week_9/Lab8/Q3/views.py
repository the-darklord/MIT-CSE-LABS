from ast import Num
from django.shortcuts import render
from .forms import LoginForm

# Create your views here.

def register(request):
    context = {}
    form = LoginForm(request.POST or None)
    context['form'] = form
    return render(request,'Q3/home.html',context)

def success(request):
    username = None
    password = None
    emailid = None
    number = None
    if request.method=="POST":
        form = LoginForm(request.POST)
        if form.is_valid():
            username = request.POST['username']
            password = request.POST['password']
            emailid = request.POST['emailid']
            number = request.POST['number']
    else:
        form = LoginForm()
            
    return render(request,'Q3/success.html',{'username':username,'password':password,'emailid':emailid,'number':number})