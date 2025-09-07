
# Application 1

Gabriel Saborido  4679215

## Analysis/Engineering

### Q1: Does anything happen to the LED if you increase the delay within the print task? What if you increase the number of characters printed? 

Nothing happens to the LED when adding the delay within the print task, but when increasing the number characters printed, 40ms of delay was added to my print task.

### Q2: Remove the vTaskDelay in the print task (making it a tight loop printing continuously). Describe the behavior you observed.

Starvation occurs and the blink task doesn't even run. The LED stays OFF and the system continuously prints.

### Q3: Assume you were a developer of one of these applications - might there be some considerations that you would want to take into consideration in how verbose (or not) you want your messages to be? Additionally, explain why this system benefits from having correct functionality at predictable times.

I chose the healthcare application. These messages need to be expressive without being complicated. As long as the patients information can be displayed to themselves or the medical team without causing confusion, then the system is successful. When a system such as a heartbeat monitor is correct and predictable, the medical team responsible for monitoring the patients heartbeat can have an accurate and consistent measurement of the patients state.

### Q4: Identify/Verify the period of each task; you can try to do this via the simulator, or perhaps by printing data to the console, or connect the outputs to the logic analyzer.

### a. Describe how you measure the periods:

Using task delay and pdMS_TO_TICKS.

### b. LED blink task period:

250ms LED on + 250ms LED off = 500ms.

### c. Print task period:

10000ms.

### Q5. Did our system tasks meet the timing requirements?

Yes.

#### How do you know?

Wokwi has a simulation timer.

#### How did you verify it?

Using print statements in the tasks that display the time.

### Q6. If the LED task had been written in a single-loop with the print (see baseline super-loop code), you might have seen the LED timing disturbed by printing (especially if printing took variable time).

#### Did you try running the code?

Yes.

#### Can you cause the LED to miss it's timing requirements?

Yes.

#### If yes, how?

I added a significant amount of extra characters to the print in longprint() and this caused about an 80ms delay on the LED toggle.

#### If no, what did you try?

### Q7. Do you agree or disagree: By using multitasking, we were able to achieve timing determinism for the LED blink. Why or why not?

Agreed. Using multitasking, both print and blink tasks were accurate down to the exact millisecond meaning the system was predictable and correct. This is exactly what a system with timing determinism strives for.
