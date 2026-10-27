class Solution(object):

    def isEscapePossible(self, blocked, source, target):
        self.blocked = blocked
        self.source = source
        self.target = target
        self.blocked_dict = {}
        self.edge_dict = {}
        self.min_x = min(self.source[0], self.target[0])
        self.max_x = max(self.source[0], self.target[0])
        self.min_y = min(self.source[1], self.target[1])
        self.max_y = max(self.source[1], self.target[1])
        for blocked_cell in blocked:
            if blocked_cell[0] in self.blocked_dict:
                self.blocked_dict[blocked_cell[0]][blocked_cell[1]] = None
            else:
                self.blocked_dict[blocked_cell[0]] = {blocked_cell[1]: None}
        for blocked_cell in self.blocked:
            exposed_faces = self.enumerate_exposed_faces(blocked_cell[0], blocked_cell[1])
            for face in exposed_faces:
                x_edge = face[3]
                y_edge = face[4]
                edge_type = face[5]
                edge_visited = x_edge in self.edge_dict and y_edge in self.edge_dict[x_edge] and (edge_type in self.edge_dict[x_edge][y_edge])
                if not edge_visited:
                    num_intervening_edges = self.check_loop(face[0], face[1], face[2])
                    if num_intervening_edges % 2 == 1:
                        return False
        return True

    def enumerate_exposed_faces(self, x, y):
        out_list = []
        for i in range(4):
            if not self.is_occupied(x + self.dxe[i], y + self.dye[i]):
                x_star = x + self.dxe2[i]
                y_star = y + self.dye2[i]
                x_edge_coords = x_star + self.dx_edge_coords[(i + 2) % 4]
                y_edge_coords = y_star + self.dy_edge_coords[(i + 2) % 4]
                out_list.append([x_star, y_star, i, x_edge_coords, y_edge_coords, self.edge_code_list[i]])
        return out_list

    def check_loop(self, x_start, y_start, starting_direction, is_cc=True):
        starting_direction = self.update_edge_direction(x_start, y_start, starting_direction, is_cc)
        direction = starting_direction
        x = x_start
        y = y_start
        num_intervening_edges = 0
        touched_grid_boundary = False
        while True:
            x_new = x + self.dxp[direction]
            y_new = y + self.dyp[direction]
            if self.edge_on_boundary(x, y, x_new, y_new):
                touched_grid_boundary = True
                break
            x_edge_coords = x + self.dx_edge_coords[direction]
            y_edge_coords = y + self.dy_edge_coords[direction]
            edge_coords = [x_edge_coords, y_edge_coords]
            if x_edge_coords in self.edge_dict:
                if y_edge_coords in self.edge_dict[x_edge_coords]:
                    if self.edge_code_list[direction] not in self.edge_dict[x_edge_coords][y_edge_coords]:
                        self.edge_dict[x_edge_coords][y_edge_coords].append(self.edge_code_list[direction])
                else:
                    self.edge_dict[x_edge_coords][y_edge_coords] = [self.edge_code_list[direction]]
            else:
                self.edge_dict[x_edge_coords] = {y_edge_coords: [self.edge_code_list[direction]]}
            if self.edge_code_list[direction] == 'v':
                if self.min_x < edge_coords[0] and edge_coords[0] <= self.max_x and (edge_coords[1] == self.source[1]):
                    num_intervening_edges += 1
            if self.edge_code_list[direction] == 'h':
                if self.min_y < edge_coords[1] and edge_coords[1] <= self.max_y and (edge_coords[0] == self.target[0]):
                    num_intervening_edges += 1
            x = x_new
            y = y_new
            direction = self.update_edge_direction(x, y, direction, is_cc)
            if x == x_start and y == y_start and (direction == starting_direction):
                break
        if touched_grid_boundary and is_cc:
            num_intervening_edges += self.check_loop(x_start, y_start, (starting_direction + 2) % 4, is_cc=False)
        return num_intervening_edges

    def update_edge_direction(self, x, y, direction, is_cc):
        x_right = x + self.dx_fwrd_right[direction]
        y_right = y + self.dy_fwrd_right[direction]
        x_left = x + self.dx_fwrd_left[direction]
        y_left = y + self.dy_fwrd_left[direction]
        if is_cc:
            if self.is_occupied(x_right, y_right):
                direction += 1
                direction %= 4
            elif not self.is_occupied(x_left, y_left):
                direction -= 1
                direction %= 4
        elif self.is_occupied(x_left, y_left):
            direction -= 1
            direction %= 4
        elif not self.is_occupied(x_right, y_right):
            direction += 1
            direction %= 4
        return direction

    def edge_on_boundary(self, x0, y0, x1, y1):
        b_test0 = x0 == 0 or x0 == self.l or y0 == 0 or (y0 == self.l)
        b_test1 = x1 == 0 or x1 == self.l or y1 == 0 or (y1 == self.l)
        return b_test0 and b_test1

    def is_occupied(self, x, y):
        return x in self.blocked_dict and y in self.blocked_dict[x] or x < 0 or y < 0 or (x == self.l) or (y == self.l)

    def __init__(self):
        self.l = 10 ** 6
        self.dxp = [0, -1, 0, 1]
        self.dyp = [-1, 0, 1, 0]
        self.dxe = [-1, 0, 1, 0]
        self.dye = [0, 1, 0, -1]
        self.dxe2 = [0, 0, 1, 1]
        self.dye2 = [0, 1, 1, 0]
        self.dx_fwrd_right = [-1, -1, 0, 0]
        self.dy_fwrd_right = [-1, 0, 0, -1]
        self.dx_fwrd_left = [0, -1, -1, 0]
        self.dy_fwrd_left = [-1, -1, 0, 0]
        self.edge_code_list = ['v', 'h', 'v', 'h']
        self.dx_edge_coords = [0, -1, 0, 0]
        self.dy_edge_coords = [-1, 0, 0, 0]
