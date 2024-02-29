import time
import random
import copy
nodes = [1,2,3,4,5,6,7]

# Election Message
# OK Message
# Coordinator Message Type
# Assuming node 7 as coordinator

coordinator = 7
time_interval = 5
failed_node_index = 6

def bully_algo(nodes,coordinator,time_interval,failed_node_index):
	print(coordinator, " is the coordinator right now")
	time.sleep(2)
	print(coordinator, " has crashed but system isn't aware of crash yet")
	temp_nodes = copy.deepcopy(nodes )
	temp_nodes.pop(failed_node_index)
	current_node = random.choice(temp_nodes)
	print(current_node, " has sent a message to coordinator")
	time.sleep(time_interval)
	print("Time interval expired")
	failed_node = coordinator
	while True:
		for i in range(current_node,failed_node_index):
			print(current_node, " sends an Election message to ",nodes[i])
		time.sleep(2)
		for i in range(current_node,failed_node_index):
			print(nodes[i], " sends an OK message to ",current_node)
		time.sleep(2)
		if nodes[current_node] == failed_node:
			break
		current_node = nodes[current_node]
	coordinator = current_node
	print(coordinator, " is the coordinator right now")
	for i in range(0,coordinator-1):
		print(coordinator, " sends Coordinator message to ",nodes[i])

if __name__ == "__main__":
	bully_algo(nodes,coordinator,time_interval,failed_node_index)


