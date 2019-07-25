 ## Interview Cake Weekly Question
 
 
 ### Given an undirected graph with maximum degree D, find a graph coloring using at most D+1 colors.


For example:



<img src="https://www.interviewcake.com/images/svgs/graph_coloring__frucht_graph_uncolored.svg?bust=203sanitize=true">



This graph's maximum degree (D) is 3, so we have 4 colors (D+1). Here's one possible coloring:



<img src="https://www.interviewcake.com/images/svgs/graph_coloring__frucht_graph_colored.svg?bust=203">



Graphs are represented by a list of N node objects, each with a label, a set of neighbors, and a color:


```python
class GraphNode:

  def __init__(self, label):
      self.label = label
      self.neighbors = set()
      self.color = None


a = GraphNode('a')
b = GraphNode('b')
c = GraphNode('c')

a.neighbors.add(b)
b.neighbors.add(a)
b.neighbors.add(c)
c.neighbors.add(b)

graph = [a, b, c]
```
