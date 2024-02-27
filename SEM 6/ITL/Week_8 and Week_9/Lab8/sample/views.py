from django.shortcuts import render,HttpResponse
from .forms import RegForm,GeeksForm,LoginForm

# Create your views here.

def home(request):
    return render(request,'sample/login.html')

def login(request):
    username = "not logged in"
    if request.method == "POST": 
        MyLoginForm = LoginForm(request.POST) 
        if MyLoginForm.is_valid(): 
            username = MyLoginForm.cleaned_data['username']
            request.session['username'] = username
        else: 
            MyLoginForm = LoginForm() 
    context = {'username': username} 
    return render(request, 'sample/loggedin.html',context) 

def formView(request):
   if request.session.has_key('username'): 
        username = request.session['username'] 
        return render(request, 'loggedin.html', {"username" : username}) 
   else: 
        return render(request, 'login.html', { })
   
def logout(request): 
    try: 
        del request.session['username'] 
    except:
       pass 
    return HttpResponse("<strong>You are logged out.</strong>") 