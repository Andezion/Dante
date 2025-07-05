pub fn read_vector(array: &mut [i32], size: usize, stop_value: i32) -> i32
{
    if size < 1 || size > 150
    {
        return -1;
    }

    let mut input: String = String::new();
    let mut counter: i32 = 0;

    for _i in 0..size
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect parsing");

        if number == stop_value
        {
            break;
        }

        array[counter as usize] = number;
        counter += 1;
    }

    counter
}

pub fn display_vector(array: & [i32], size: usize)
{
    if size <= 0
    {
        return;
    }

    for i in 0..size
    {
        print!("{} ", array[i]);
    }
    println!();
}

pub fn bubble_sort(array: &mut [i32], size: usize) -> i32
{
    if size <= 0
    {
        return 1;
    }

    for _i in 0..size - 1
    {
        let mut pointer: u8 = 0;
        for j in 0..size - 1
        {
            if array[j] > array[j + 1]
            {
                (array[j], array[j + 1]) = (array[j + 1], array[j]);
                pointer = 1;
            }
        }
        display_vector(& array, size);
        if pointer == 0
        {
            break;
        }
    }

    0
}
