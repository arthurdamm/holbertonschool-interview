#!/usr/bin/python3
# Lock Boxes Interview Algorithm


def canUnlockAll(boxes):
    """Solves the problem"""
    if not boxes or not len(boxes):
        return True

    visited = [False for i in range(len(boxes))]

    def visitBox(box):
        """Visits each box"""
        if visited[box]:
            return
        visited[box] = True
        for _box in boxes[box]:
            visitBox(_box)

    visitBox(0)
    return all(visited)
