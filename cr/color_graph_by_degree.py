from random import choices


class GraphNode:

    def __init__(self, label: str):
        self.label = label
        self.neighbors = set()
        self.color = None


def get_max_degree_and_q(node: object) -> tuple:
    """Takes a node object creates a queue and performs a BFS to identify the maximum degree of the graph."""
    qu = [node]  # initialize with the input node
    visited = []
    degree_list = set()

    while qu:
        current_node = qu.pop(0)
        degree_list.add(len(current_node.neighbors))
        visited.append(current_node)

        for item in current_node.neighbors:
            if item not in visited and item not in qu:
                qu.append(item)
    return max(degree_list), visited


def make_color_choices(list_length: int) -> list:
    """Creates a list of random color choices the length of the max graph degree plus one."""
    return list(choices(color_list, k=(list_length + 1)))


def color_graph(node: object) -> str:
    """Iterates through the queue and adds a color value to each node. Neighbors should not receive the same color."""
    color_qu = get_max_degree_and_q(node)[1]
    number_of_colors = get_max_degree_and_q(node)[0]
    color_choices = make_color_choices(number_of_colors)
    color_incrementer = 0

    while color_qu:
        node_to_color = color_qu.pop(0)
        neighbor_colors = [neighbor.color for neighbor in node_to_color.neighbors]

        if node_to_color.color is None:

            while color_choices[color_incrementer] in neighbor_colors:
                color_incrementer += 1

                if color_incrementer > number_of_colors:
                    color_incrementer = 0
            node_to_color.color = color_choices[color_incrementer]
            print(node_to_color.label, node_to_color.color)  # Optional print statement
    return "Done!"


""" Test Graph

a = GraphNode('a')
b = GraphNode('b')
c = GraphNode('c')
d = GraphNode('d')
e = GraphNode('e')
f = GraphNode('f')
g = GraphNode('g')
h = GraphNode('h')
i = GraphNode('i')
j = GraphNode('j')
k = GraphNode('k')
l = GraphNode('l')

a.neighbors.add(b)
a.neighbors.add(g)
a.neighbors.add(h)
b.neighbors.add(a)
b.neighbors.add(i)
b.neighbors.add(c)
c.neighbors.add(b)
c.neighbors.add(d)
c.neighbors.add(i)
d.neighbors.add(c)
d.neighbors.add(e)
d.neighbors.add(k)
e.neighbors.add(d)
e.neighbors.add(f)
e.neighbors.add(l)
f.neighbors.add(e)
f.neighbors.add(g)
f.neighbors.add(l)
g.neighbors.add(f)
g.neighbors.add(a)
g.neighbors.add(h)
h.neighbors.add(a)
h.neighbors.add(g)
h.neighbors.add(j)
i.neighbors.add(b)
i.neighbors.add(c)
i.neighbors.add(j)
j.neighbors.add(k)
j.neighbors.add(i)
j.neighbors.add(h)
k.neighbors.add(j)
k.neighbors.add(d)
k.neighbors.add(l)
l.neighbors.add(f)
l.neighbors.add(k)
l.neighbors.add(e)
"""

""" Test Color List
color_list = ['amber','amethyst','apricot','aqua','aquamarine','auburn','azure','beige','black','blue','bronze','brown',
              'burnt umber','cardinal','carmine','celadon','cerise','cerulean','charcoal','chartreuse','chocolate',
              'cinnamon','copper','coral','cream','crimson','cyan','dark','denim','desert sand','ebony','ecru',
              'eggplant','emerald','forest green','fuchsia','gold','goldenrod','gray','green','grey','hot pink',
              'indigo','ivory','jade','jungle green','kelly green','khaki','lavender','lemon','lilac','lime','magenta',
              'mahogany','maroon','mauve','mustard','navy blue','ocher','olive','orange','orchid','pale','pastel',
              'peach','periwinkle','persimmon','pewter','pink','primary','pumpkin','purple','red','rose','ruby',
              'russet','rust','saffron','salmon','sapphire','scarlet','sea green','sepia','shamrock green','sienna',
              'silver','slate','steel blue','tan','tangerine','taupe','teal','terracotta','thistle','tomato red',
              'topaz','turquoise','ultramarine','umber','vermilion','violet','veridian','wheat brown','white','yellow']
"""