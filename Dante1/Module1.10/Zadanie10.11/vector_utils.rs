use std::cmp::PartialEq;
#[derive(PartialEq, Debug)]
pub enum Direction
{
    RotateRight,
    RotateLeft
}

pub fn shift(array: &mut [i32], array_size: usize, pos_to_swift: i32, dir: Direction) -> i32
{
    if (dir != Direction::RotateLeft && dir != Direction::RotateRight) || array_size <= 0
    {
        return 1;
    }

    if pos_to_swift == 0
    {
        return 0;
    }

    if dir == Direction::RotateLeft
    {
        for _i in 0..(pos_to_swift % (array_size as i32))
        {
            let temp: i32 = array[array_size - 1];

            for _j in (1..array_size).rev()
            {
                array[_j] = array[_j - 1];
            }

            // let mut j: usize = array_size - 1;
            // while j > 0
            // {
            //     array[j] = array[j - 1];
            //     j -= 1;
            // }
            array[0] = temp;
        }
    }
    if dir == Direction::RotateRight
    {
        for _i in 0..pos_to_swift
        {
            let temp: i32 = array[0];
            for j in 0..array_size - 1
            {
                array[j] = array[j + 1];
            }
            array[array_size - 1] = temp;
        }
    }

    0
}

pub fn read_vector(array: &mut [i32], size: usize, stop_value: i32) -> i32
{
    if size < 1 || size > 150
    {
        return -1;
    }

    let mut input: String = String::new();
    let mut counter: i32 = 0;

    for i in 0..size
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect parsing");

        if number == stop_value
        {
            break;
        }

        array[i] = number;
        counter += 1;
    }

    if counter > 150
    {
        counter = 150;
    }

    counter
}

pub fn display_vector(array: & [i32], size: i32)
{
    if size < 0
    {
        return;
    }

    for i in 0..size
    {
        print!("{} ", array[i as usize]);
    }
}
