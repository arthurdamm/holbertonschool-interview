#!/usr/bin/python3
# Lock Boxes Interview Algorithm


def canUnlockAll(boxes):
    """Solves the problem"""
    if not isinstance(boxes, list):
        return False
    if not len(boxes):
        return True
    visited = [False for i in range(len(boxes))]
    stack = [0]
    while len(stack):
        box = stack.pop(0)
        visited[box] = True
        if not isinstance(boxes[box], list):
            continue
        for _box in boxes[box]:
            try:
                if isinstance(_box, int) and _box >= 0 and _box < len(boxes)\
                  and not visited[_box]:
                    stack.append(_box)
            except Exception:
                pass
    return all(visited)
