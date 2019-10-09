# Hacktoberfest'19
Hacktoberfest® is open to everyone in our global community. Whether you’re a developer, student learning to code, event host, or company of any size, you can help drive growth of open source and make positive contributions to an ever-growing community. All backgrounds and skill levels are encouraged to complete the challenge.  

* Hacktoberfest is open to everyone in our global community!
* Pull requests can be made in any GitHub-hosted repositories/projects.
* Sign up anytime between October 1 and October 31.

## Support open source and earn a limited edition T-shirt!
### Rules
To qualify for the official limited edition Hacktoberfest shirt, you must register and make four pull requests (PRs) between October 1-31 (in any time zone).
PRs can be made to any public repo on GitHub, not only the ones with issues labeled **Hacktoberfest**.
If a maintainer reports your pull request as spam or behavior not in line with the project’s code of conduct, you will be ineligible to participate.
This year, the first 50,000 participants who successfully complete the challenge will earn a T-shirt.

Read more about [participation details](https://hacktoberfest.digitalocean.com/details).

## Guidelines to Contribute here
### Follow these steps to make your first pull request

* Fork this repository
* Clone your forked repository to your local machine
* Add any **Algorithm** (any language) in its respective folder (ex. Bubble sort in Sorting Algorithms)
(If folder is not there you can create one)
* Add your name in Contributors.md file
* Then create a pull request
* Congratulations!! You have successfully created your pull request.
* Check your progress here (https://hacktoberfest.digitalocean.com/profile)
* Wait for the T-Shirt
import java.util.Arrays;
import java.util.stream.Collectors;

public class BubbleSortExample{

    public static void main(String[] args) {

        int[] array = {99, 88, 55, 77, 1, 66};

        System.out.print("unsorted data: ");
        printArray(array);

        System.out.print("ascending order: "); //1,55,66,77,88,99
        bubble_sort(array);

        printArray(array);

        System.out.print("descending order: "); //99,88,77,66,55,1
        bubble_sort(array, false);

        printArray(array);

    }

    private static void bubble_sort(int[] input) {
        bubble_sort(input, true);
    }

    private static void bubble_sort(int[] input, boolean ascending) {

        int inputLength = input.length;
        int temp;
        boolean is_sorted;

        for (int i = 0; i < inputLength; i++) {

            is_sorted = true;

            for (int j = 1; j < (inputLength - i); j++) {

                if (ascending) {
                    if (input[j - 1] > input[j]) {
                        temp = input[j - 1];
                        input[j - 1] = input[j];
                        input[j] = temp;
                        is_sorted = false;
                    }
                } else {
                    if (input[j - 1] < input[j]) {
                        temp = input[j - 1];
                        input[j - 1] = input[j];
                        input[j] = temp;
                        is_sorted = false;
                    }

                }

            }

            // is sorted? then break it, avoid useless loop.
            if (is_sorted) break;

        }

    }

    private static void printArray(int[] data) {
        String result = Arrays.stream(data)
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(","));
        System.out.println(result);
    }

}
