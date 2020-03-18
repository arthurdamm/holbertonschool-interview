#!/usr/bin/python3
"""
Script to parse stdin for a line of logging:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
"""
import re
import sys

CODES = {200, 301, 400, 401, 403, 404, 405, 500}

codes = {code: 0 for code in CODES}
codes["size"] = 0


def print_metrics():
    """Prints the summary of total file size and lines per status code"""
    print("File size:", codes["size"])
    for code in CODES:
        if code in codes and codes[code] > 0:
            print("{}: {}".format(code, codes[code]))


def parse_log():
    """Parses the stdin line by line for log info"""
    i = 1
    for line in sys.stdin:
        try:
        	line = line[:-1]
            words = line.split(" ")
            if len(words) < 2:
                continue
            code, size = 0, 0
            try:
                size = int(words[-1])
            except ValueError:
                pass
            try:
                code = int(words[-2])
            except ValueError:
                pass
            codes["size"] += size
            if code in codes:
                codes[code] += 1
            if not i % 10:
                print_metrics()
            i += 1
        except:
            pass

if __name__ == "__main__":
    try:
        parse_log()
    except KeyboardInterrupt:
        print_metrics()
        raise
        pass
    print_metrics()
