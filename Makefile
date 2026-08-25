.PHONY: watch list verify check hint

PYTHON ?= python3

watch:
	$(PYTHON) clings.py watch

list:
	$(PYTHON) clings.py list

verify:
	$(PYTHON) clings.py verify

check:
	$(PYTHON) clings.py check

hint:
	$(PYTHON) clings.py hint
