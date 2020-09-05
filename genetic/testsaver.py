

class TestSaver:

    def __init__(self, filePath):
        self.file = open(filePath, "w");
        self.file.write('test_input' + ' - ' + 'coverage_score' + '\n');
        self.file.write('---------------------------' + '\n');

    def save_test_case(self, testcase):
            self.file.write(testcase[0] + ' - ' + str(testcase[1]) + '\n');

    def save_list(self, tests):
        for test in tests:
            self.save_test_case(test);

        self.file.close();


