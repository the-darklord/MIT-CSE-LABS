import time
import random
import copy

def ring_algo():
	nodes = [1,2,3,4,5,6,7]
	coordinator = 4
	failed_node_index = 3
	noNodes = len(nodes)
	time_interval = 5

	print(coordinator, " is the coordinator right now")
	time.sleep(2)
	print(coordinator, " has crashed but system isn't aware of crash yet")
	temp_nodes = copy.deepcopy(nodes) 
	temp_nodes.pop(failed_node_index)
	initiator = random.choice(temp_nodes)
	print(initiator, " has sent a message to coordinator")
	time.sleep(time_interval)
	print("Time interval expired")
	failed_node = coordinator
	print(initiator, " is the initiator")
	current_node_index = initiator-1
	election_list = [initiator]
	current_node_index = current_node_index+1
	current_node = nodes[(current_node_index)%noNodes]
	print("Election Message List: ",election_list)
	while current_node != initiator:
		election_list.append(current_node)
		current_node_index = current_node_index+1
		current_node = nodes[(current_node_index)%noNodes]
		if current_node == failed_node:
			current_node_index = current_node_index+1
			current_node = nodes[(current_node_index)%noNodes]
		print("Election Message List: ",election_list)
		time.sleep(1)
	maxNode = election_list[0]
	for i in range(0,len(election_list)):
		if(election_list[i] > maxNode):
			maxNode = election_list[i]
	coordinator = maxNode
	print(coordinator, " is the coordinator right now")
	current_node_index = initiator - 1
	current_node = nodes[(current_node_index+1)%noNodes]
	current_node_index = current_node_index+1
	time.sleep(1)
	while current_node != initiator:
		print(initiator, " sends Coordinator message as ",coordinator," as the coordinator to ", current_node)
		current_node = nodes[(current_node_index+1)%noNodes]
		current_node_index = current_node_index+1
		time.sleep(1)
if __name__ == "__main__":
	ring_algo()

