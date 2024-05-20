import unittest
from apollolib.sorting import quicksort

class TestQuicksort(unittest.TestCase):
    def test_quicksort(self):
        data = [5, 2, 9, 1, 5, 6]
        result = quicksort(data)
        self.assertEqual(result, [1, 2, 5, 5, 6, 9])

if __name__ == '__main__':
    unittest.main()