rule_list = ["A N B", "B NE C", "C N A"]                    # test input -> invalid


def process_rules(input_rules: list) -> str:

    working_list = [rule.split(" ") for rule in input_rules]  # split each rule: "B NE C" -> [B, NE, C]
    north_dict = {}
    south_dict = {}
    east_dict = {}
    west_dict = {}

    for rule_part in working_list:
        direction = rule_part[1]
        left_node = rule_part[0]
        right_node = rule_part[2]

        if direction[0] == "N":

            validator = dfs_before_insert(north_dict, left_node, right_node)

            if validator is True:
                north_dict[left_node] = right_node
                south_dict[right_node] = left_node

            else:

                return "Invalid Rule: %(r)s is already north of %(l)s" % {'r': right_node, 'l': left_node}

        if direction[0] == "S":

            validator = dfs_before_insert(south_dict, left_node, right_node)

            if validator is True:

                north_dict[left_node] = right_node
                south_dict[right_node] = left_node

            else:

                return "Invalid Rule: %(r)s is already south of %(l)s" % {'r': right_node, 'l': left_node}

        if len(direction) > 1:

            if direction[1] == "E":

                validator = dfs_before_insert(east_dict, left_node, right_node)

                if validator is True:
                    east_dict[left_node] = right_node
                    west_dict[right_node] = left_node

                else:

                    return "Invalid Rule: %(r)s is already east of %(l)s" % {'r': right_node, 'l': left_node}

            if direction[1] == "W":

                validator = dfs_before_insert(west_dict, left_node, right_node)

                if validator is True:

                    west_dict[left_node] = right_node
                    east_dict[right_node] = left_node

                else:

                    return "Invalid Rule: %(r)s is already west of %(l)s" % {'r': right_node, 'l': left_node}

    return "All rules are valid"


def dfs_before_insert(dir_dict: dict, ln: str, rn: str) -> bool:

    val = rn

    while val in dir_dict.keys():

        val = dir_dict[val]

        if val is ln:

            return False

    return True
