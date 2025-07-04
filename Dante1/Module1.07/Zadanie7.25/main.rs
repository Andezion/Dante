use std::mem::swap;
use std::ptr;

fn read_vector(array: &mut [i32; 501], size: i32, stop_value: i32) -> i32
{
    if size <= 0
    {
        panic!("Error in read_vector!");
    }

    let mut counter: i32 = 0;
    let mut input: String = String::new();

    for i in 0..size
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect parse");

        if number == stop_value
        {
            break;
        }

        array[i as usize] = number;
        counter += 1;
    }
    counter
}

fn display_vector(array: & [i32; 501], size: i32)
{
    if size <= 0
    {
        return;
    }

    for i in 0..size
    {
        print!("{} ", array[i as usize]);
    }
    println!();
}

fn swap_vector(array_one: &mut [i32; 501], size_one: i32, array_two: &mut [i32; 501], size_two: i32)
{
    if size_one <= 0 || size_two <= 0
    {
        return;
    }

    if size_one < size_two
    {
        for i in 0..size_one
        {
            let temp: i32 = array_one[i as usize];
            array_one[i as usize] = array_two[i as usize];
            array_two[i as usize] = temp;

            swap(&mut array_one[i as usize], &mut array_two[i as usize]);

            (array_one[i as usize], array_two[i as usize]) = (array_two[i as usize], array_one[i as usize]);
        }
    }
    else
    {
        for i in 0..size_two
        {
            let temp: i32 = array_one[i as usize];
            array_one[i as usize] = array_two[i as usize];
            array_two[i as usize] = temp;

            swap(&mut array_one[i as usize], &mut array_two[i as usize]);

            (array_one[i as usize], array_two[i as usize]) = (array_two[i as usize], array_one[i as usize]);
        }
    }
}

fn main()
{
    let mut array_one:[i32; 501] = [0; 501];
    println!("Enter: ");

    let mut size_one: i32 = read_vector(&mut array_one, 500, 0);
    if size_one < 0
    {
        panic!("Error!");
    }
    if size_one < 1
    {
        panic!("Not enough data available");
    }
    if size_one > 50
    {
        size_one = 50;
    }

    let mut array_two:[i32; 501] = [0; 501];
    println!("Enter: ");

    let mut size_two = read_vector(&mut array_two, 500, 0);
    if size_two < 0
    {
        panic!("Error!");
    }
    if size_two < 1
    {
        panic!("Not enough data available");
    }
    if size_two > 50
    {
        size_two = 50;
    }

    display_vector(&mut array_two, size_two);
    display_vector(&mut array_one, size_one);

    swap_vector(&mut array_one, size_one, &mut array_two, size_two);

    display_vector(&mut array_two, size_two);
    display_vector(&mut array_one, size_one);
}
