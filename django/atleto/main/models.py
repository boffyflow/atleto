from django.db import models

class Athlete( models.Model):
    firstname = models.CharField( max_length=200)
    lastname = models.CharField( max_length=200)
    dob = models.DateField()
    height = models.IntegerField( default=175)

    def __str__( self):
        return self.firstname + ' ' + self.lastname

class Run( models.Model):
    starttime = models.DateTimeField()
    endtime = models.DateTimeField()
    location = models.ForeignKey( 'Location', on_delete=models.SET_NULL, null=True)

class Location( models.Model):
    name = models.CharField( max_length=200)

    def __str__( self):
        return name