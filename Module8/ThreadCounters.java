/** Demonstrates two counters coordinated with Thread.join(). */
public class ThreadCounters {
    private static final int MIN_COUNT = 0;
    private static final int MAX_COUNT = 20;

    private static void countUp() {
        System.out.println("Thread 1: Counting up");

        for (int counter = MIN_COUNT; counter <= MAX_COUNT; counter++) {
            if (Thread.currentThread().isInterrupted()) {
                return;
            }
            System.out.println(counter);
        }

        System.out.println("Thread 1 completed.\n");
    }

    private static void countDown() {
        System.out.println("Thread 2: Counting down");

        for (int counter = MAX_COUNT; counter >= MIN_COUNT; counter--) {
            if (Thread.currentThread().isInterrupted()) {
                return;
            }
            System.out.println(counter);
        }

        System.out.println("Thread 2 completed.");
    }

    public static void main(String[] args) {
        Thread firstThread = new Thread(ThreadCounters::countUp, "Count-Up");
        Thread secondThread = new Thread(ThreadCounters::countDown, "Count-Down");

        System.out.println("Two-Thread Counter Application (Java)\n");

        try {
            firstThread.start();
            firstThread.join();

            // Start the second worker only after the first has finished.
            secondThread.start();
            secondThread.join();

            System.out.println("\nBoth threads finished successfully.");
        } catch (InterruptedException exception) {
            // Request worker cancellation and preserve main's interrupt status.
            firstThread.interrupt();
            secondThread.interrupt();
            Thread.currentThread().interrupt();
            System.err.println("Execution interrupted; cancellation requested.");
        }
    }
}
