#!/usr/bin/python3
# Lock Boxes Interview Algorithm


def canUnlockAll(boxes):
    """Solves the problem"""

    try:
        visited = [False for i in range(len(boxes))]
        stack = [0]
        while len(stack):
            box = stack.pop(0)
            visited[box] = True
            for _box in boxes[box]:
                if not visited[_box]:
                    stack.append(_box)
        return all(visited)
    except Exception:
        return False
