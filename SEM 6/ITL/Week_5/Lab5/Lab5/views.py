from django.shortcuts import render 
from django.http import HttpResponse 
from datetime import date 
import calendar 
from calendar import HTMLCalendar

def index(request): 
	return HttpResponse("<H2>Welcome to Index !!!</H2>")

def hello(request):
	return HttpResponse("<H2>Welcome to IT Lab !!!</H2>")

def Calendar(request,year,month):
	year = int(year)
	month = int(month)
	if year<1900 or year>2099:
		year = date.today().year
	month_name = calendar.month_name[month]
	title = "My Club Event Calendar - %s\t%s"%(month_name,year)
	cal = HTMLCalendar().formatmonth(year,month)
	return HttpResponse("<center><h1>%s</h1><br><br><p>%s</p></center>"%(title,cal))
	