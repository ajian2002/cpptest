import time
import telepot
import json
from telepot.loop import MessageLoop
from telepot.delegate import pave_event_space, per_chat_id, create_open
from telepot.namedtuple import ReplyKeyboardMarkup

class GoldenArches(telepot.helper.ChatHandler):
    def __init__(self, *args, **kwargs):
        super(GoldenArches, self).__init__(*args, **kwargs)
        
        self.indicator = 'choose_order'
        self.order = {}

    def on_chat_message(self, msg):
        content_type, chat_type, chat_id = telepot.glance(msg)
        if self.indicator == 'add url':
            
            self.indicator = 'choose_payment'
        elif self.indicator == 'choose_payment':
            self.order['order'] = msg['text']
            
            self.indicator = 'set_order'
        elif self.indicator == 'set_order':
            self.order['payment'] = msg['text']
            
            with open('order.json', 'a') as handle:
                json.dump(self.order, handle)
                handle.write("\n")
                handle.close()
            bot.sendMessage(chat_id, 'Order Accepted')


token = '741409888:AAFd63l_boS5xLuWUWx1Ff1ZxlnfUKKkv2w'
#bot = telepot.Bot(token)
bot = telepot.DelegatorBot(token, [pave_event_space()(per_chat_id(), create_open, GoldenArches,timeout=10),])
MessageLoop(bot).run_as_thread()
print('Listening ...')
while 1:
    time.sleep(10)
