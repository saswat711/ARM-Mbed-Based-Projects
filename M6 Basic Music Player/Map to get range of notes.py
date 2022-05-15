NewMin = 0.2;
NewMax = 1;
OldMin = 16.35;
OldMax = 30.87;

OldValue =  29.14;

OldRange = (OldMax - OldMin)  
NewRange = (NewMax - NewMin)  
NewValue = (((OldValue - OldMin) * NewRange) / OldRange) + NewMin

print(NewValue)
