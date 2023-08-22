class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
    // constructor
    Command(const std::string& name) : name(name) {}

    std::string name;
};
