import sys

N = int(sys.stdin.readline())

l = []

for _ in range(N):
    l.append(int(sys.stdin.readline()))
def Swap(left, right):
    temp = left
    left = right
    right = temp

    return left, right
    

def Sorting(start, end):
    pivot = l[(start + end) // 2]
    left = start
    right = end
    while(left < right):
        while(l[left] < pivot and left < right):
            left += 1
        while(l[right] > pivot):    
            right -= 1
        
        if(left < right):
            l[left], l[right] = Swap(l[left], l[right])
    return right   
    

def QuickSort(start, end):
    if (start >= end):
        return

    pivot = Sorting(start, end)
    QuickSort(start, pivot-1)
    QuickSort(pivot+1, end)


QuickSort(0, len(l)-1)

for i in range(len(l)):
    sys.stdout.write(str(l[i]) + "\n")
