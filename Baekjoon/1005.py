T = int(input())
for i in range(T):
	N, K = map(int, input().split())
	
	build = [[False for col in range(N)]for row in range(N)]
	table = [0 for i in range(N)]
	
	D = list(map(int, input().split()))
	
	for ii in range(N):
		X, Y = map(int, input().split())
		
		build[X-1][Y-1] = True
		table[Y-1] += 1

	W = int(input())
	t = 0
	queue = []
	order = []
	end = False 
	while(not end):
    	# Push in Queue
		for ii in range(N):
			if(table[ii] == 0):
				queue.append(ii)
				table[ii] = -1
				
				
		
		m = 0
		for o in queue:
			
			if(m < D[o]):
				m = D[o]

			if(o + 1 == W):
				t += D[o]
				
				end = True
				break
		
		if(end):
			break
		
		t += m
		if(not end):
			for q in queue:
				order.append(q)
				for ii in range(N):
					if(build[q][ii] == True):
						build[q][ii] = False
						table[ii] -= 1
			
			queue = []
			
			
						
						
	print(t)
