from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request,'Q4/index.html')