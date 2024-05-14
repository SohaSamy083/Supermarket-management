$("#getData").click(function () {
    //ajax call

    $.ajax({
        url: 'https://jsonplaceholder.typicode.com/todos',
        type: 'get',
        dataType: 'json',
        data: {
            "id": 5,
            "title": "et porro tempora"
        },
        success: function (res) {
            console.log(res[0])
        },
        error: function (xhr) {
            console.log(xhr)
        },
        beforeSend: function (xhr) {
            console.log("Merihan")
        },
        complete: function (xhr) {
            console.log("Finished......")
        }
    })
})

