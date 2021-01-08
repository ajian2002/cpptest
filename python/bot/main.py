
from telepot.loop import MessageLoop
from pprint import pprint
import time
import telepot
from telepot.delegate import pave_event_space, per_chat_id, create_open
from telepot.namedtuple import ReplyKeyboardMarkup
from telepot.namedtuple import InlineKeyboardMarkup, InlineKeyboardButton


def handle(msg):
    # pprint(msg)

    if telepot.flavor(msg) == 'chat':
        content_type, chat_type, chat_id = telepot.glance(msg)
        # print(content_type, chat_type, chat_id, sep=" ")
        # text
        # private  私人的
        # 用户id 591197749
        if msg['text'] == '/food':
            bot.sendMessage(chat_id, 'hamburger')
        elif msg['text'] == '/drink':
            bot.sendMessage(chat_id, 'coke zero')
        elif msg['text'] == '/start1':  # custom keyboard
            keyboard1 = [['McFlurry'], ['Nugget'], ['Coke'], ['Fries']]

            mark_up = ReplyKeyboardMarkup(
                keyboard=keyboard1, one_time_keyboard=True)

            text = 'What would you like to order?'

            bot.sendMessage(chat_id, text, reply_markup=mark_up)
        elif msg['text'] == '/start2':  # inline keyboard
            # menu = ['Nugget', 'McFlurry', 'Coke', 'Fries']
            menu = [('McFlurry', 'McFlurry'), ('Nugget', 'Nugget'),
                    ('Coke', 'Coke'), ('Fries', 'Fries')]
            kb = []
            for t in menu:
                kb.append([InlineKeyboardButton(
                    text=t[0], callback_data=t[1])])
            mark_up = InlineKeyboardMarkup(
                inline_keyboard=kb, one_time_keyboard=True)
            bot.sendMessage(
                chat_id, 'What would you like to order?', reply_markup=mark_up)

            # print(msg)

        else:
            bot.sendMessage(chat_id, msg['text'])
    elif telepot.flavor(msg) == 'callback_query':
        query_id, from_id, query_data = telepot.glance(
            msg, flavor='callback_query')
        bot.answerCallbackQuery(query_id, text='Sold out!')
        bot.answerCallbackQuery(
            query_id, text='You have ordered'+query_data)


token = '741409888:AAFd63l_boS5xLuWUWx1Ff1ZxlnfUKKkv2w'
bot = telepot.Bot(token)
# print(bot.getMe())
# pprint(bot.getMe())
# message 的key包括chat(用户的名字，ID和聊天的种类（在telegram中，聊天的种类分为三种，private, group以及channel，我们更多地是handle private的信息)），date（消息发送的日期），from（发送者的信息），message_id（一个独特的，message_id可以specify某一条信息），而text就是用户所发送消息的文本。
response = bot.getUpdates()

# 参数指开始值
count = 0
messageid = 0
# messageid = 165886077
# response = bot.getUpdates(offset=messageid)
'''
while count < 3:
    response = bot.getUpdates(offset=messageid)
    while (response == []):
        response = bot.getUpdates(offset=messageid)
    messageid += 1
    count += 1
    pprint(response)
'''
# pprint(response)
# pprint 指pretty print，是python自带的一个可以让打印出来的dictionary更美观的一个function


# 'run_as_thread'在这里起到了，只要你启动了你的python file，那么这个MessageLoop就会永续不断地运行下去，除非遇到特殊情况（冲突或者恶性bug等等）
# MessageLoop需要两个argument，一个是你已经specify token的'bot'，而另一个就是告诉MessageLoop如何处理信息的'method'
MessageLoop(bot, handle).run_as_thread()
#MessageLoop(bot, {'chat': on_chat_message,'callback_query': on_callback_query}).run_as_thread()
print('Listening ...')

# Keep the program running.
while 1:
    time.sleep(10)


# inline keyboard 出现在输入区之上，
# 而custom keyboard出现在键盘输入区之下；


'''
{'message': {'chat': {'first_name': 'ajian',
                       'id': 591197749,
                       'last_name': 'ajian',
                       'type': 'private',
                       'username': 'yegetablesvac'},
              'date': 1609838598,
              
            //  'entities': [{'length': 6, 'offset': 0, 'type': 'bot_command'}],
            
              'from': {'first_name': 'ajian',
                       'id': 591197749,
                       'is_bot': False,
                       'language_code': 'zh-hans',
                       'last_name': 'ajian',
                       'username': 'yegetablesvac'},
              'message_id': 837,
              // 'text': '/start'},
              
  'update_id': 165886072},
  
 {'message': {'chat': {'first_name': 'ajian',
                       'id': 591197749,
                       'last_name': 'ajian',
                       'type': 'private',
                       'username': 'yegetablesvac'},
              'date': 1609838909,
              'from': {'first_name': 'ajian',
                       'id': 591197749,
                       'is_bot': False,
                       'language_code': 'zh-hans',
                       'last_name': 'ajian',
                       'username': 'yegetablesvac'},
              'message_id': 838,
              'text': 'hello'},

'''
'''
{
    'id': '2539175001051914633', 
    'from': 
    {
        'id': 591197749, 
        'is_bot': False, 
        'first_name': 'ajian', 
        'last_name': 'ajian', 
        'username': 'yegetablesvac', 
        'language_code': 'zh-hans'
    },
    'message': 
    {
                'message_id': 911,
                'from': 
                {
                    'id': 741409888,
                    'is_bot': True, 
                    'first_name': 'dikassrdikassr.of.bot.',
                    'username': 'asfasfsadghsdrhgdszadtbot'
                },
                
                'chat':
                {
                    'id': 591197749,
                    'first_name': 'ajian',
                    'last_name': 'ajian',
                    'username': 'yegetablesvac',
                    'type': 'private'
                },
                
                'date': 1609852227,
                'text': 'What would you like to order?', 
                'reply_markup': 
                {
                    'inline_keyboard': 
                    [
                        [{'text': 'McFlurry', 'callback_data': 'McFlurry'}],
                        [{'text': 'Nugget', 'callback_data': 'Nugget'}],
                        [{'text': 'Coke', 'callback_data': 'Coke'}], 
                        [{'text': 'Fries', 'callback_data': 'Fries'}]
                    ]            
                }
                
    },
    'chat_instance': '5794076197296578557', 
    'data': 'Nugget'
}
"

'''
