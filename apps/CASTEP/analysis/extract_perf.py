import sys
import re

filename = sys.argv[1]

infile = open(filename, 'r')

# Loop through the CASTEP output extracting SCF cycle timings
tvals = []
for line in infile:
   if re.search('<-- SCF', line):
      line = line.strip()
      tokens = line.split()
      if re.match('[0-9]+', tokens[0].lstrip()):
         tvals.append(float(tokens[4]))

if len(tvals) < 3:
   print("Error: not enough timing data in CASTEP output")

# Compute the SCF cycle times and remove extreme values
deltat = []
for i in range(len(tvals)-1):
   deltat.append(tvals[i+1] - tvals[i])
deltat.remove(max(deltat))
deltat.remove(min(deltat))

# Calculate performance
tSCF = sum(deltat)/len(deltat)
perf = 1.0 / tSCF

print(f'     Timing = {tSCF:.6f} s per SCF cycle')
print(f'Performance = {perf:.6f} SCF cycles per s')

