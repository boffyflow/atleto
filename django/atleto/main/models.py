from django.db import models
from django.urls import reverse
from django.db.models import Sum

class RunSplit( models.Model):
    dist = models.FloatField()
    t = models.FloatField()
    heartrate = models.IntegerField( default=0)
    notes = models.TextField( blank=True, null=True)

    def __str__( self):
        return 'runsplit'

class Athlete( models.Model):
    firstname = models.CharField( max_length=200)
    lastname = models.CharField( max_length=200)
    dob = models.DateField()
    height = models.IntegerField( default=175)
    runs = models.ForeignKey( 'Run', on_delete=models.SET_NULL, null=True)

    def __str__( self):
        return self.firstname + ' ' + self.lastname

class Run( models.Model):
    starttime = models.DateTimeField()
    endtime = models.DateTimeField()
    location = models.OneToOneField( 'Location', on_delete=models.SET_NULL, null=True)
    splits = models.ForeignKey( 'RunSplit', on_delete=models.SET_NULL, null=True)

    def __str__( self):
        return self.location.__str__()

    def distance( self, unit='km'):
        return RunSplit.objects.aggregate( Sum( 'dist'))

class Location( models.Model):
    name = models.CharField( max_length=200)

    def __str__( self):
        return self.name