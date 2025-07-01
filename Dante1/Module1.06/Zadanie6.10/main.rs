fn counter_for_column(array: [[i32; 10]; 10], j: usize) -> i32
{
    let mut sum: i32 = 0;
    for i in 0..10
    {
        sum += array[i][j];
    }
    sum
}

fn counter_for_row(array: [[i32; 10]; 10], i: usize) -> i32
{
    let mut sum: i32 = 0;
    for j in 0..10
    {
        sum += array[i][j];
    }
    sum
}

fn result_counter(array: [[i32; 10]; 10], i: usize, j: usize) -> i32
{
    return -1 * (counter_for_column(array, j) - counter_for_row(array, i));
}

fn main()
{
    let mut array:[[i32; 10]; 10] = [[0; 10]; 10];
    let mut input: String = String::new();

    for i in 0..10
    {
        for j in 0..10
        {
            input.clear();

            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            array[i][j] = input.trim().parse().expect("Incorrect parse");
        }
    }
    
    let mut pointer: bool = false;
    let mut max: i32 = array[0][0];
    
    for i in 0..10
    {
        for j in 0..10
        {
            if array[i][j] % 2 == 0
            {
                if array[i][j] > max
                {
                    max = array[i][j];    
                }
                pointer = true;
            }
        }
    }
    
    if pointer == false
    {
        panic!("Nothing to show");
    }
    
    for i in 0..10
    {
        for j in 0..10
        {
            if max == array[i][j]
            {
                println!("{} {} {}", i, j, result_counter(array, i, j));
            }
        }
    }
}
