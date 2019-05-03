from django.shortcuts import HttpResponse

def index( request):
    print( request)
    return HttpResponse( "up and running")