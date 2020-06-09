#!/usr/bin/python3
"""Finds how much rainwater is caught"""


def rain(walls):
    """Solves the algo"""
    if not walls or len(walls) < 3:
        return 0
    left_peaks = [0] * len(walls)
    left_peaks[0] = walls[0]
    for i in range(1, len(walls)):
        left_peaks[i] = max(left_peaks[i - 1], walls[i])
    water = 0
    right_peak = walls[-1]
    for i in range(len(walls) - 2, -1, -1):
        w = min(left_peaks[i], right_peak) - walls[i]
        right_peak = max(walls[i], right_peak)
        water += w if w > 0 else 0
    return water
