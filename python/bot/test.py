from pprint import pprint
msg = '
{
    "ok": true,
    "result":
    [
        {"update_id": 165886138,
         "callback_query":
            {
                "id": "2539174998809284029",
                "from":
                {
                    "id": 591197749, "is_bot": false, "first_name": "ajian", "last_name": "ajian", "username": "yegetablesvac", "language_code": "zh-hans"
                },
                "message":
                {
                    "message_id": 917,
                    "from":
                    {
                        "id": 741409888, "is_bot": true, "first_name": "dikassrdikassr.of.bot.", "username": "asfasfsadghsdrhgdszadtbot"
                    },
                    "chat":
                    {
                        "id": 591197749, "first_name": "ajian", "last_name": "ajian", "username": "yegetablesvac", "type": "private"
                    },
                    "date": 1609853883, "text": "What would you like to order?", "reply_markup":
                    {
                        "inline_keyboard":
                        [
                            [{"text": "McFlurry", "callback_data": "McFlurry"}],
                            [{"text": "Nugget", "callback_data": "Nugget"}],
                            [{"text": "Coke", "callback_data": "Coke"}],
                            [{"text": "Fries", "callback_data": "Fries"}]
                        ]
                    }
                },
                "chat_instance": "5794076197296578557",
                "data": "Coke"
            }
         }
    ]
}'
mmsg ='
{'message': {'chat': {'first_name': 'ajian',
                      'id': 591197749,
                      'last_name': 'ajian',
                      'type': 'private',
                      'username': 'yegetablesvac'},
             'date': 1609838598,

             // 'entities': [{'length': 6, 'offset': 0, 'type': 'bot_command'}],

             'from': {'first_name': 'ajian',
                      'id': 591197749,
                      'is_bot': False,
                      'language_code': 'zh-hans',
                      'last_name': 'ajian',
                      'username': 'yegetablesvac'},
             'message_id': 837,
             // 'text': '/start'},

 'update_id': 165886072}'
pprint(msg)
