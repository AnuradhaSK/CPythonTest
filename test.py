import tensorflow as tf

# Settings
flags = tf.app.flags
FLAGS = flags.FLAGS

#core params..
flags.DEFINE_string('model', 'gcn', 'model name')
flags.DEFINE_string('learning_rate', "0.01", 'initial learning rate')
flags.DEFINE_string("model_size", "small", "define model size")
flags.DEFINE_string("graph_id", "2", "define model size")
flags.DEFINE_string("train_worker", "0", "define model size")


def main(argv=None):
    print("Flags Set")
    print(FLAGS.learning_rate)
    print(FLAGS.train_worker)

if __name__ == '__main__':
   main()