from django.shortcuts import render

# Create your views here.

def home(request):
    return render(request,'Q5/home.html')

def metadata(request):
    return render(request,'Q5/metadata.html')

def publisher(request):
    return render(request,'Q5/publisher.html')

def reviews(request):
    return render(request,'Q5/reviews.html')