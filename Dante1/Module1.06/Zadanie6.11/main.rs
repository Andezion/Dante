fn main()
{
    let mut array:[[i32; 10]; 10] = [[0; 10]; 10];
    println!("Enter: ");

    let mut max: i32 = i32::MAX;
    let mut max_i: i32 = 0;
    let mut max_j: i32 = 0;

    let mut min: i32 = i32::MIN;
    let mut min_i: i32 = 0;
    let mut min_j: i32 = 0;

    let mut sum: i32 = 0;

    let mut input: String = String::new();
    for i in 0..10
    {
        for j in 0..10
        {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            array[i][j] = input.trim().parse().expect("Incorrect parsing");

            sum += array[i][j];
            if max < array[i][j]
            {
                max = array[i][j];
                max_i = i as i32;
                max_j = j as i32;
            }
            if min > array[i][j]
            {
                min = array[i][j];
                min_i = i as i32;
                min_j = j as i32;
            }
        }
    }

    let middle: i32 = sum / 100;
    let mut counter1: i32 = 0;
    let mut counter2: i32 = 0;
    let mut counter3: i32 = 0;

    let mut middle_i: i32 = 0;
    let mut middle_j: i32 = 0;

    for i in 0..10
    {
        for j in 0..10
        {
            if array[i][j] == min
            {
                counter1 += 1;
            }
            if array[i][j] == max
            {
                counter2 += 1;
            }
            if array[i][j] == middle
            {
                counter3 += 1;

                middle_i = i as i32;
                middle_j = j as i32;
            }
        }
    }

    if counter1 == 0 || counter2 == 0 || counter3 == 0
    {
        panic!("Error!");
    }

    let dist1: f32 = f32::sqrt(f32::powi((min_i - max_i) as f32, 2) - f32::powi((min_j - max_j) as f32, 2));
    let dist2: f32 = f32::sqrt(f32::powi((middle_i - min_i) as f32, 2) - f32::powi((middle_j - min_j) as f32, 2));
    let dist3: f32 = f32::sqrt(f32::powi((max_i - middle_i) as f32, 2) - f32::powi((max_j - middle_j) as f32, 2));
    
    println!("{} {} {}", dist1, dist2, dist3);
}
