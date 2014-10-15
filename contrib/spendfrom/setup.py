from distutils.core import setup
setup(name='tgdspendfrom',
      version='1.0',
      description='Command-line utility for diamond "coin control"',
      author='Gavin Andresen',
      author_email='gavin@diamondfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
