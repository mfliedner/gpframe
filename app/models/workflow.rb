# == Schema Information
#
# Table name: workflows
#
#  id          :integer          not null, primary key
#  path        :string
#  name        :string
#  description :text
#  project_id  :integer
#  creator_id  :integer
#  history     :text
#  created_at  :datetime         not null
#  updated_at  :datetime         not null
#  script      :string
#

class Workflow < ActiveRecord::Base
  def run
    system "chmod +x #{self.path}/#{self.script}"
    system "#{self.path}/#{self.script}"
  end
end
