#!/usr/bin/python3
# Lock Boxes Interview Algorithm


def canUnlockAll(boxes):
    """Solves the problem"""
    unlocked = set()
    visited = set()
    unlocked.add(0)

    def visitBox(box):
        """Visits each box"""
        if box in visited:
            return
        visited.add(box)
        for _box in boxes[box]:
            unlocked.add(_box)
        for _box in boxes[box]:
            visitBox(_box)

    visitBox(0)
    return len(unlocked) == len(boxes)
